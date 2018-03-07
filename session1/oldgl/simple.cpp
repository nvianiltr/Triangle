#include <GL/glut.h>



void mydisplay(){
     glClear(GL_COLOR_BUFFER_BIT); 
	/***
	 glBegin(GL_POLYGON);        
		glVertex2f(-0.5, -0.5);        
		glVertex2f(-0.5, 0.5);        
		glVertex2f(0.5, 0.5);        
		glVertex2f(0.5, -0.5);    
	glEnd();
	***/

	GLUquadricObj *p;
	p = gluNewQuadric();               /*set up object*/
	gluQuadricDrawStyle(p, GLU_LINE);  /*render style*/
	//gluCylinder(p, BASE_RADIUS, TOP_RADIUS, BASE_HEIGHT, sections, slices);
	gluCylinder(p, 50, 50, 50, 5, 5);
	glFlush(); 
}

void myReshape(int w, int h)
{
    glMatrixMode (GL_PROJECTION);    /* prepare for and then */ 
    glLoadIdentity ();               /* define the projection */
    glFrustum (-1.0, 1.0, -1.0, 1.0, /* transformation */
                   1.5, 20.0); 
    glMatrixMode (GL_MODELVIEW);  /* back to modelview matrix */
    glViewport (0, 0, w, h);      /* define the viewport */
}

int main(int argc, char** argv){
	    glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (500, 500);
	glutCreateWindow("simple");  
	//myinit ();
    glutReshapeFunc(myReshape);
	glutDisplayFunc(mydisplay);
    glutMainLoop();
}
