// xl: id module
// Copyright (C) 2012 Juan Manuel Borges Caño

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <stdlib.h>
#include <string.h>

#define ID_SMALL_STORE 256
#define ID_MEDIUM_STORE 1024
#define ID_LARGE_STORE 4096
#define ID_EXTRA_LARGE_STORE 16384

// idGenIdsDecl
#define idGenIdsDecl(prefix, Names); \
	void \
	prefix ## Gen ## Names(unsigned int count, unsigned int *ids);

// idDeleteIdsDecl
#define idDeleteIdsDecl(prefix, Names); \
	void \
	prefix ## Delete ## Names(unsigned int count, unsigned int *ids);

// idBindIdDecl
#define idBindIdDecl(prefix, Name); \
	void \
	prefix ## Bind ## Name(unsigned int id);

// idCreateDecl
#define idCreateDecl(prefix, Name); \
	void \
	prefix ## Name ## Create(void);

// idDestroyDecl
#define idDestroyDecl(prefix, Name); \
	void \
	prefix ## Name ## Destroy(void);

// idDeclareIrregularAPI
#define idDeclareIrregularAPI(prefix, Name, Names); \
	\
	idCreateDecl(prefix, Name); \
	\
	idDestroyDecl(prefix, Name); \
	\
	idGenIdsDecl(prefix, Names); \
	\
	idDeleteIdsDecl(prefix, Names); \
	\
	idBindIdDecl(prefix, Name);

// idDeclareAPI
#define idDeclareAPI(prefix, Name); \
	idDeclareIrregularAPI(prefix, Name, Name ## s);

// idGenObjects
#define idGenObjects(type, initializer, n, objects, store, size) \
	{ \
		unsigned int generated = 0; \
		unsigned int i; \
		for(i = 0; i < size && generated < n; i++) \
		{ \
			if(!store[i]) \
			{ \
				store[i] = (type *) malloc(sizeof(type)); \
				initializer(store[i]); \
				objects[generated++] = i; \
			} \
		} \
	}

// idGenIdsDef
#define idGenIdsDef(prefix, PREFIX, name, Name, Names, init, store, STORE); \
	void \
	prefix ## Gen ## Names(unsigned int count, unsigned int *ids) \
	{ \
		idGenObjects(PREFIX ## name, init, count, ids, store, STORE); \
	}

// idDeleteObjects
#define idDeleteObjects(terminator, n, objects, store) \
	{ \
		unsigned int i; \
		for(i = 0; i < n; i++) \
		{ \
			terminator(store[objects[i]]); \
			free(store[objects[i]]); \
			store[objects[i]] = NULL; \
		} \
	}


// idDeleteIdsDef
#define idDeleteIdsDef(prefix, Names, term, store); \
	void \
	prefix ## Delete ## Names(unsigned int count, unsigned int *ids) \
	{ \
		idDeleteObjects(term, count, ids, store); \
	}

// idBindIdDef
#define idBindIdDef(prefix, name, Name, store); \
	void \
	prefix ## Bind ## Name(unsigned int id) \
	{ \
		name = store[id]; \
	}

// idClearStore
#define idClearStore(type, store, size) \
	memset(store, 0, size * sizeof(type *))

// idCreateDef
#define idCreateDef(prefix, PREFIX, name, Name, create, store, STORE); \
	void \
	prefix ## Name ## Create(void) \
	{ \
		idClearStore(PREFIX ## name, store, STORE); \
		create(); \
	}

// idDestroyDef
#define	idDestroyDef(prefix, Name, destroy); \
	void \
	prefix ## Name ## Destroy(void) \
	{ \
		destroy(); \
	}

// idDefineIrregularAPI
#define idDefineIrregularAPI(prefix, PREFIX, name, Name, Names, create, init, term, destroy, STORE); \
	static PREFIX ## name *store[STORE]; \
	static PREFIX ## name *name; \
	\
	idCreateDef(prefix, PREFIX, name, Name, create, store, STORE); \
	\
	idDestroyDef(prefix, Name, destroy); \
	\
	idGenIdsDef(prefix, PREFIX, name, Name, Names, init, store, STORE); \
	\
	idDeleteIdsDef(prefix, Names, term, store); \
	\
	idBindIdDef(prefix, name, Name, store);
	

// idDefineAPI
#define idDefineAPI(prefix, PREFIX, name, Name, create, init, term, destroy, STORE); \
	idDefineIrregularAPI(prefix, PREFIX, name, Name, Name ## s, create, init, term, destroy, STORE);

// idVoidCreate
#define idVoidCreate(); \
	static \
	void \
	idCreate() \
	{ \
	}

// idVoidInit
#define idVoidInit(PREFIX, name); \
	static \
	void \
	idInit(PREFIX ## name *name) \
	{ \
		memset(name, 0, sizeof(PREFIX ## name)); \
	}

// idVoidTerm
#define idVoidTerm(PREFIX, name); \
	static \
	void \
	idTerm(PREFIX ## name *name) \
	{ \
	}

// idVoidDestroy
#define idVoidDestroy(); \
	static \
	void \
	idDestroy() \
	{ \
	}

// idStoreDecl
#define idStoreDecl(prefix, PREFIX, name, Name); \
	PREFIX ## name * \
	prefix ## Name ## Store(unsigned int id);

// idStoreDef
#define idStoreDef(prefix, PREFIX, name, Name); \
	PREFIX ## name * \
	prefix ## Name ## Store(unsigned int id) \
	{ \
		return store[id]; \
	}

// idTypeDecl
#define idTypeDecl(prefix, PREFIX, name, Nam); \
	void \
	prefix ## Nam ## Type(unsigned int id, PREFIX ## name *t);

// idTypeDef
#define idTypeDef(prefix, PREFIX, name, Nam); \
	void \
	prefix ## Nam ## Type(unsigned int id, PREFIX ## name *t) \
	{ \
		PREFIX ## name *name; \
		name = store[id]; \
		memcpy(name, t, sizeof(PREFIX ## name)); \
	}

// idUnloadIdDecl
#define idUnloadIdDecl(prefix, Name); \
	void \
	prefix ## Name ## Unload(unsigned int id);

// idUnloadIdsIrregularDecl
#define idUnloadIdsIrregularDecl(prefix, Names); \
	void \
	prefix ## Names ## Unload(unsigned int n, unsigned int *ids);

// idUnloadIrregularDecl
#define idUnloadIrregularDecl(prefix, Name, Names); \
	idUnloadIdDecl(prefix, Name); \
	\
	idUnloadIdsIrregularDecl(prefix, Names);

// idUnloadDecl
#define idUnloadDecl(prefix, Name); \
	idUnloadIrregularDecl(prefix, Name, Name ## s);

// idUnloadIdDef
#define idUnloadIdDef(prefix, PREFIX, name, Name, idUnload); \
	void \
	prefix ## Name ## Unload(unsigned int id) \
	{ \
		PREFIX ## name *name; \
		\
		name = store[id]; \
		\
		idUnload(name); \
		\
		memset(name, 0, sizeof(PREFIX ## name)); \
	}

// idUnloadIdsIrregularDef
#define idUnloadIdsIrregularDef(prefix, Name, Names); \
	void \
	prefix ## Names ## Unload(unsigned int n, unsigned int *ids) \
	{ \
		unsigned int i; \
		\
		for(i = 0; i < n; i++) \
			prefix ## Name ## Unload(ids[i]); \
	}

// idUnloadIrregularDef
#define idUnloadIrregularDef(prefix, PREFIX, name, Name, Names, idUnload); \
	idUnloadIdDef(prefix, PREFIX, name, Name, idUnload); \
	\
	idUnloadIdsIrregularDef(prefix, Name, Names);

// idUnloadDef
#define idUnloadDef(prefix, PREFIX, name, Name, idUnload); \
	idUnloadIrregularDef(prefix, PREFIX, name, Name, Name ## s, idUnload);
