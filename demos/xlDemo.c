/*

**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  
 ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  
**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****

		 Open X Library: Multiple Purpose C Open Engine

                                  **  ** **  
                                   ****  **  
                                  **  ** ****

                   Licensed GPLv3 by Juan Manuel Borges Caño
                  * Homepage <http://code.google.com/p/openxl>
                     * Mail <mailto:juanmabcmail@gmail.com>
                   * Blog <http://juanmabcblog.blogspot.com>
               Copyright (C) 2012 - 2014 Juan Manuel Borges Caño

**  ** **     **  ** **     **  ** **    **  ** **     **  ** **     **  ** **  
 ****  **      ****  **      ****  **     ****  **      ****  **      ****  **  
**  ** ****   **  ** ****   **  ** ****  **  ** ****   **  ** ****   **  ** ****

*/

#include "xlDemo.h"
#include <config.h>

XLid xlDemoWindow, xlDemoViewport, xlDemoOperator, xlDemoLogoCamera;
XLid xlDemoFont, xlDemoSound;
XLid xlStringList;
XLreal xlDemoTicks = XL_REAL(0.015);
XLuint xlDemoFrames;
XLstring xlDemoTitle;

static XLreal xlDemoFramesSeconds;
static XLuint xlDemoClockTicks, xlDemoStart, xlDemoEnd;
static XLreal xlDemoRotation;
static XLreal xlDemoLogoSize[3] = { XL_REAL(0), XL_REAL(0), XL_REAL(1.0) };

static float xlDemoLightCoords[2][4] = {
	{ XL_REAL(0), XL_REAL(10), XL_REAL(10), XL_REAL(1) },
	{ XL_REAL(0), XL_REAL(10), XL_REAL(-10), XL_REAL(1) }
};

void
xlDemoKeyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27: glutLeaveMainLoop(); break;
		default: demoKeyboard(key, x, y); break;
	}
}

void
xlDemoReshape(int width, int height)
{
	XLint size[2] = { width, height };
	xlSetIntegerv(XL_VIEWPORT_PROPERTY_SIZE, size);
	xlVptProperty();
}

static
void
xlDemoLogoDisplay(void)
{
	XLpoint translation;
	XLvector scale;
	XLreal aspect;
	XLreal width, height;

	if(xlGetMaterial()) xlMatBegin();
	glPushMatrix();

	width = xlGetInteger(XL_VIEWPORT_PROPERTY_WIDTH);
	height = xlGetInteger(XL_VIEWPORT_PROPERTY_HEIGHT);
	aspect = width / height;

	xlPointAssignReals(&translation, XL_REAL(0.55) * aspect, - XL_REAL(0.425), -XL_REAL(1.25));
	xlTranslate(&translation);
	
	xlRotate(xlDemoRotation, xlVectorY);

	xlVectorAssignReals(&scale, XL_REAL(0.375) / xlDemoLogoSize[0], XL_REAL(0.375) / xlDemoLogoSize[1], XL_REAL(0.075));
	xlScale(&scale);
	
	xlPointAssignArray(&translation, xlDemoLogoSize);
	xlPointAssignReals(xlPointTMP, XL_REAL(-0.5), XL_REAL(-0.5), XL_REAL(0.5));
	xlPointMult(&translation, xlPointTMP);
	xlTranslate(&translation);

	glCallList(xlStringList);

	glPopMatrix();
	if(xlGetMaterial()) xlMatEnd();
}

void
xlDemoDisplay(void)
{
	xlDemoStart = xlTimes(NULL);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	xlOpCameraProperty();
	xlOpBegin();
	glLightfv(GL_LIGHT1, GL_POSITION, xlDemoLightCoords[0]);
	glLightfv(GL_LIGHT2, GL_POSITION, xlDemoLightCoords[1]);
	xlCamCalcFrustum();
	demoDisplay();
	xlOpEnd();

	glClear(GL_DEPTH_BUFFER_BIT);

	xlBindCamera(xlDemoLogoCamera);
	xlCamProperty();
	xlCamBegin();
	xlDemoLogoDisplay();
	xlCamEnd();

	xlWinSwapBuffers();

	xlDemoEnd = xlTimes(NULL);

	xlDemoFramesSeconds += XL_REAL(xlDemoEnd - xlDemoStart) / XL_REAL(xlDemoClockTicks);
	xlDemoFrames++;

	if(xlDemoFrames == 25)
	{
		xlDemoFramesSeconds = XL_REAL(25) / xlDemoFramesSeconds;
		xlStringPrintFormatted(xlDemoTitle, XL_STRING_SIZE, L"XL %ls Demo (FPS: %f)", xlVersion, xlDemoFramesSeconds);
		xlSetString(XL_WINDOW_PROPERTY_TITLE, xlDemoTitle);
		xlWinProperty();
		xlDemoFramesSeconds = XL_REAL(0);
		xlDemoFrames = 0;
	}
}

void
xlDemoTimer(int value)
{
	xlDebug(__FILE__, __LINE__);

	xlTimeSync(xlDemoTicks);

	xlOpSync();

	demoTimer(value);
	xlDemoRotation += xlTimeDelta * XL_REAL(500);

	xlWinPostRedisplay();
	glutTimerFunc(xlTimeDelta * XL_REAL(1000), xlDemoTimer, 0);
}


void
xlDemoLoad(int *argc, char **argv)
{
	XLint position[2], size[2];
	const float lghtamb[4] = { XL_REAL(0.05), XL_REAL(0.05), XL_REAL(0.05), XL_REAL(1) };
	const float lghtdfs[4] = { XL_REAL(0.75), XL_REAL(0.75), XL_REAL(0.75), XL_REAL(1) };
	const float lghtspc[4] = { XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5), XL_REAL(1) };
	const float fogcol[4] = { XL_REAL(0.5), XL_REAL(0.5), XL_REAL(0.5), XL_REAL(1)};

	xlRandSeed(xlTime(NULL));

	xlDemoClockTicks = xlClockTicks();

	//xlSetLogLevel(XL_LOG_LEVEL_NULL);

	xlLogBanner();

	alutInit(argc, argv);
	glutInit(argc, argv);

	xlGenWindows(1, &xlDemoWindow);
	xlBindWindow(xlDemoWindow);
	xlDataLoad("data/windows/Default.xlc");
	xlStringPrintFormatted(xlDemoTitle, XL_STRING_SIZE, L"XL %ls Demo", xlGetString(XL_VERSION));
	xlSetString(XL_WINDOW_PROPERTY_TITLE, xlDemoTitle);
	size[0] = XL_REAL(glutGet(GLUT_SCREEN_WIDTH)) * XL_REAL(3) / XL_REAL(4);
	size[1] = XL_REAL(glutGet(GLUT_SCREEN_HEIGHT)) * XL_REAL(3) / XL_REAL(4);
	//xlSetIntegerv(XL_WINDOW_PROPERTY_SIZE, size);
	position[0] = XL_REAL(glutGet(GLUT_SCREEN_WIDTH) - xlGetInteger(XL_WINDOW_PROPERTY_WIDTH)) / XL_REAL(2);
	position[1] = XL_REAL(glutGet(GLUT_SCREEN_HEIGHT) - xlGetInteger(XL_WINDOW_PROPERTY_HEIGHT)) / XL_REAL(2);
	xlSetIntegerv(XL_WINDOW_PROPERTY_POSITION, position);
	xlWinCreate();

	xlGenViewports(1, &xlDemoViewport);
	xlBindViewport(xlDemoViewport);
	xlDataLoad("data/viewports/Default.xlc");

	//glClearColor(XL_COLOR_PARAMS(xlColorBlue));
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glShadeModel(GL_FLAT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glAlphaFunc(GL_GREATER, XL_REAL(0.05));
	glEnable(GL_ALPHA_TEST);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lghtamb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lghtdfs);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lghtspc);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lghtamb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lghtdfs);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lghtspc);
	glLightfv(GL_LIGHT1, GL_POSITION, xlDemoLightCoords[0]);
	glLightfv(GL_LIGHT2, GL_AMBIENT, lghtamb);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lghtdfs);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lghtspc);
	glLightfv(GL_LIGHT2, GL_POSITION, xlDemoLightCoords[1]);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lghtamb);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
	//glColorMaterial(GL_FRONT, GL_AMBIENT);
	//glEnable(GL_POLYGON_SMOOTH);
	//glEnable(GL_AUTO_NORMAL);
	//glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glFogfv(GL_FOG_COLOR, fogcol);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, XL_REAL(2500));
	glFogf(GL_FOG_END, XL_REAL(5000));
	glFogf(GL_FOG_DENSITY, XL_REAL(0.10));
	glEnable(GL_FOG);

	xlDataAdd("data/images/Textil.xl", myImgTextilXL);
	xlDataAdd("data/images/Wood.xl", myImgWoodXL);
	xlDataAdd("data/images/Grass.xl", myImgGrassXL);
	xlDataAdd("data/materials/Test.xl", myMatTestXL);
	xlDataAdd("data/surfaces/Test.xl", mySurfTestXL);
	xlDataAdd("data/objects/Cube.xl", myObjCubeXL);
	xlDataAdd("data/models/Cube.xl", myModCubeXL);

	xlDemoFrames = 0;
	xlDemoRotation = XL_REAL(0);

	xlGenFonts(1, &xlDemoFont);
	xlBindFont(xlDemoFont);
	xlDataLoad("data/fonts/Default.xlc");
	xlFntGenFace("data/fonts");
	xlFntProperty();

	xlStrSize(xlXL, &xlDemoLogoSize[0], &xlDemoLogoSize[1]);
	xlStringList = glGenLists(1);
	glNewList(xlStringList, GL_COMPILE);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        //glEnable(GL_TEXTURE_GEN_R);
        //glEnable(GL_TEXTURE_GEN_Q);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	//glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	//glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	xlVectorAssignReals(xlVectorTMP, XL_REAL(1) / XL_REAL(8) / XL_REAL(xlGetInteger(XL_FONT_PROPERTY_WIDTH)), XL_REAL(1) / XL_REAL(8) / XL_REAL(xlGetInteger(XL_FONT_PROPERTY_HEIGHT)), XL_REAL(1) /XL_REAL(8));
	xlScale(xlVectorTMP);
	glMatrixMode(GL_MODELVIEW);
	xlStrDraw(XL_RENDER_SOLID, xlDemoLogoSize[2], xlXL);
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
        //glDisable(GL_TEXTURE_GEN_Q);
        //glDisable(GL_TEXTURE_GEN_R);
        glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_GEN_S);
	glEndList();

	xlGenCameras(1, &xlDemoLogoCamera);
	xlBindCamera(xlDemoLogoCamera);
	xlDataLoad("data/cameras/Default.xlc");

	xlGenOperators(1, &xlDemoOperator);
	xlBindOperator(xlDemoOperator);;
	//xlOpCompile(xlDemoOperatorPath);
	xlDataLoad(xlDemoOperatorPath);
	xlOpGenCamera("data/cameras");

	xlGenSounds(1, &xlDemoSound);
	xlBindSound(xlDemoSound);
	xlDataLoad("data/sounds/abe-intro.ogg");
	xlSndGenBuffer();
	xlSndGenSource();
	xlSndPlay();

	demoLoad(argc, argv);

	glutDisplayFunc(xlDemoDisplay);
	glutReshapeFunc(xlDemoReshape);
	glutKeyboardFunc(xlDemoKeyboard);

	glutTimerFunc(xlDemoTicks * XL_REAL(1000), xlDemoTimer, 0);
}

void
xlDemoUnload()
{
	demoUnload();

	xlSndStop();
	xlSndDeleteSource();
	xlSndDeleteBuffer();
	xlSndUnload();
	xlDeleteSounds(1, &xlDemoSound);

	xlOpDeleteCamera();
	xlOpUnload();
	xlDeleteOperators(1, &xlDemoOperator);

	xlBindCamera(xlDemoLogoCamera);
	xlCamUnload();
	xlDeleteCameras(1, &xlDemoLogoCamera);

	xlFntDeleteFace();
	xlFntUnload();
	xlDeleteFonts(1, &xlDemoFont);

	xlVptUnload();
	xlDeleteViewports(1, &xlDemoViewport);

	xlWinUnload();
	xlDeleteWindows(1, &xlDemoWindow);

	xlDatasRemove();

	alutExit();
}


int
main(int argc, char **argv)
{
	xlDemoLoad(&argc, argv);
	atexit(xlDemoUnload);

	xlWinLoop();

	return EXIT_SUCCESS;
}
