# ofxDigitaktControl

Repository to control the parameters of the [Digitakt](https://www.elektron.se/products/digitakt/) from [Openframeworks](https://openframeworks.cc/)


This isn't a real addon, but it has the parameters pre defined for easier control.

Find a pre-Comlied version of it [here](./example/bin/example.app).
You will need to have the 1.11 firmware or newer for the Digitakt, and MAC OS Mojave (10.14.6), or newer.


- - - -

![.](assets/digitakt.png)

![.](assets/controls.png)

[.](assets/digitaktControl.gif)


- - - -

### Structure
The addon works with [ofxGUI](https://github.com/openframeworks/openFrameworks/tree/master/addons/ofxGui) and [ofxMidi](https://github.com/danomatika/ofxMidi), that's the only dependency.

The structure of the control panel is simple :
* the parameters are sent when the Send buttons are triggered:
each of them sends to each different panels on the Digitakt.
* the parameters are set for each channel, each channel is set in the mainParams.


## Getting Started
Plug the Digitakt to the computer using the USB cable which comes with it.
</br></br>
Download the addon ofxMidi, from [here](https://github.com/danomatika/ofxMidi).
Check that the addon is working before trying this.
The second addon (ofxGui), is native of Openframeworks.
</br>
Update the example using the project generator.
</br>
Try the example.

## License

This project is licensed under the MIT License - see the [LICENSE.md](./LICENSE) file for details.


## Acknowledgments

* [Elektron](https://www.elektron.se)
* [Dan Wilcox](https://github.com/danomatika/ofxMidi)

:floppy_disk:

## TODO
negatives float values not working properly.
Listeners on the sliders, and send to the digitakt without packages problems.
Load the data from the Digitakt setup.
