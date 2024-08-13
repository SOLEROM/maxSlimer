# dataset

* [CamVid](http://mi.eng.cam.ac.uk/research/projects/VideoRec/CamVid/)

![alt text](image.png)


## num of classes

c33

```
    {
        'name': 'CamVid_s352_c33',
        'input': (48, 88, 88),
        'output': ('None', 'Animal', 'Archway', 'Bicyclist', 'Bridge', 'Building', 'Car',
                   'CartLuggagePram', 'Child', 'Column_Pole', 'Fence', 'LaneMkgsDriv',
                   'LaneMkgsNonDriv', 'Misc_Text', 'MotorcycleScooter', 'OtherMoving',
                   'ParkingBlock', 'Pedestrian', 'Road', 'RoadShoulder', 'Sidewalk', 'SignSymbol',
                   'Sky', 'SUVPickupTruck', 'TrafficCone', 'TrafficLight', 'Train', 'Tree',
                   'Truck_Bus', 'Tunnel', 'VegetationMisc', 'Void', 'Wall'),
        'loader': camvid_get_datasets_s352_c33,
        'fold_ratio': 4,
    },
```



c3


```
    {
        'name': 'CamVid_s80_c3',  # 3 classes
        'input': (3, 80, 80),
        'output': (0, 1, 2, 3),
        'weight': (1, 1, 1, 0.14),
        'loader': camvid_get_datasets_s80_c3,
    },

```


