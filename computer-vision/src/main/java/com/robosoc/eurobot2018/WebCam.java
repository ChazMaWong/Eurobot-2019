package com.robosoc.eurobot2018;

import org.openimaj.image.MBFImage;
import org.openimaj.video.capture.Device;
import org.openimaj.video.capture.VideoCapture;
import org.openimaj.video.capture.VideoCaptureException;

public class WebCam implements ImageSource {
	
	private static final int CAMERA_WIDTH = 640;
	private static final int CAMERA_HEIGHT = 480;
	private Device videoDevice;
	
	public WebCam(Device videoDevice) {
		this.videoDevice = videoDevice;
	}

	@Override
	public MBFImage getImage() {
		MBFImage frame = null;
		
		try(VideoCapture vidCap = new VideoCapture(CAMERA_WIDTH, CAMERA_HEIGHT, videoDevice)) {
			frame = vidCap.getNextFrame();
		} catch (VideoCaptureException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return frame;
	}

}
