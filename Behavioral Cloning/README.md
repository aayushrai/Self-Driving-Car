# Behavioral Cloning 

A convolutional neural network to clone driving behavior. The model outputs a steering angle to an autonomous vehicle.

The model uses the image data and steering angles to train a neural network and then use this model to drive the car autonomously around the track.

Required files for the project: 
* Train_simulator.ipynb (script used to create and train the model)
* drive.py (script to drive the car)
* model.h5 (a trained Keras model)

## Steps
* Use the simulator to collect data of good driving behavior 
* Design, train and validate a model that predicts a steering angle from image data
* Use the model to drive the vehicle autonomously around the first track in the simulator. The vehicle should remain on the road for an entire loop around the track.

## Details About Files

### `model.py`

This is the script used to create and train the model.

#### Pipeline: 
- Create dataset by extracting image data and steering angles from csv file.
- Use _generators_ for memory efficiency.
- Split the dataset into training and validation.
- Built a convolutional neural network. 
- Save the model (any method can be used: either **model.save(model.h5)** or using **checkpoints**).

### `drive.py`

Usage of `drive.py` requires you have saved the trained model as an h5 file, i.e. `model.h5`. See the [Keras documentation](https://keras.io/getting-started/faq/#how-can-i-save-a-keras-model) for how to create this file.
```sh
model.save(filepath)
```

Once the model has been saved, it can be used with drive.py using this command:

```sh
python drive.py model.h5
```

The above command will load the trained model and use the model to make predictions on individual images in real-time and send the predicted angle back to the server via a websocket connection.
