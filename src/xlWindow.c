#include "XL/xlWindow.h"
#include "XL/xl.h"

static
void
xlOpenGLDebugCallbackARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, GLvoid *user)
{
	xlLog(L"GL debug callback:%s", message);
	xlLog(L":");
	switch(source)

	{
		case GL_DEBUG_SOURCE_API_ARB: xlLog(L"api"); break;
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB: xlLog(L"window system"); break;
		case GL_DEBUG_SOURCE_SHADER_COMPILER_ARB: xlLog(L"shader compiler"); break;
		case GL_DEBUG_SOURCE_THIRD_PARTY_ARB: xlLog(L"third party"); break;
		case GL_DEBUG_SOURCE_APPLICATION_ARB: xlLog(L"application"); break;
		case GL_DEBUG_SOURCE_OTHER_ARB: xlLog(L"other"); break;
	}
	xlLog(L":");
	switch(type)
	{
		case GL_DEBUG_TYPE_ERROR_ARB: xlLog(L"error"); break;
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB: xlLog(L"deprecated"); break;
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB: xlLog(L"undefined"); break;
		case GL_DEBUG_TYPE_PORTABILITY_ARB: xlLog(L"portability"); break;
		case GL_DEBUG_TYPE_PERFORMANCE_ARB: xlLog(L"performance"); break;
		case GL_DEBUG_TYPE_OTHER_ARB: xlLog(L"other"); break;
	}
	xlLog(L":");
	switch(severity)
	{
		case GL_DEBUG_SEVERITY_LOW_ARB: xlLog(L"low"); break;
		case GL_DEBUG_SEVERITY_MEDIUM_ARB: xlLog(L"medium"); break;
		case GL_DEBUG_SEVERITY_HIGH_ARB: xlLog(L"high"); break;
	}
	xlLog(L"\n");
}

void
xlWinCreate(void)
{
	XLwindow *bind = xlGetWindow();
	XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
	XLpath title;

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(XL_PAIR_X(&property->position), XL_PAIR_Y(&property->position));
	glutInitWindowSize(XL_PAIR_X(&property->size), XL_PAIR_Y(&property->size)); 
	xlPathPrintFormatted(title, XL_PATH_SIZE, "%ls", property->title);
#ifdef XL_DEBUG
	glutInitContextFlags(GLUT_DEBUG);
#endif
	glutCreateWindow(title);
	glewInit();
#ifdef XL_DEBUG
	if(GLEW_ARB_debug_output)
	{
		GLuint ids = 0;

		glDebugMessageCallbackARB(xlOpenGLDebugCallbackARB, NULL);
		glDebugMessageControlARB(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, &ids, GL_TRUE);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
	}
#endif

	glDebug(__FILE__, __LINE__);
}

void
xlWinSwapBuffers(void)
{
	glutSwapBuffers();
}

void
xlWinPostRedisplay(void)
{
	glutPostRedisplay();
}

void
xlWinLoop(void)
{
	glutMainLoop();
}

void
xlWinLeave(void)
{
	glutLeaveMainLoop();
}

void
xlWinProperty(void)
{
	XLwindow *bind = xlGetWindow();
	XLWindowProperty *property = &bind->body.properties[bind->runtime.property];
	XLpath title;

	xlPathPrintFormatted(title, XL_PATH_SIZE, "%ls", property->title);
	glutSetWindowTitle(title);

	glDebug(__FILE__, __LINE__);
}
