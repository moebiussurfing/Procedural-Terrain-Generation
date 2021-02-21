#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0);

	#ifdef USE_COLOR_CLIENT
	ofBackground(gui.colorBackGround);
#endif
	
	guiVisibility = true;
}

void ofApp::draw() {
	if (gui.getIsAnySettingChanged()) {
		terrainGenerator.setup(gui.getSettings());
		gui.setIsAnySettingChanged();
	}

	terrainGenerator.draw();

	if (guiVisibility) {
		gui.draw();
	}
}

void ofApp::keyPressed(int key) {
	if (key == 'g') { //Space key
		guiVisibility = !guiVisibility;
	}
	if (key == OF_KEY_RETURN) {
		gui.random();
	}

}

