# (3) Evaluation

env: (ai8x-training)

## largeUnet

* gpuDev

    python train.py --deterministic --model ai85unetlarge --out-fold-ratio 4 --dataset CamVid_s352_c3 --device MAX78000 --qat-policy policies/qat_policy_camvid.yaml --use-bias --evaluate -8 --exp-load-weights-from ../test2_unet/best-fakept-q.pth.tar --save-sample 10 --compiler-mode none


```
=> loading checkpoint /home/vlad/max78/test2_unet/latest_log_dir/best-q.pth.tar
=> Checkpoint contents:
+----------------------+-------------+---------------+
| Key                  | Type        | Value         |
|----------------------+-------------+---------------|
| arch                 | str         | ai85unetlarge |
| compression_sched    | dict        |               |
| epoch                | int         | 19            |
| extras               | dict        |               |
| optimizer_state_dict | dict        |               |
| optimizer_type       | type        | Adam          |
| state_dict           | OrderedDict |               |
+----------------------+-------------+---------------+

=> Checkpoint['extras'] contents:
+-----------------+--------+-------------------+
| Key             | Type   | Value             |
|-----------------+--------+-------------------|
| best_epoch      | int    | 19                |
| best_mAP        | int    | 0                 |
| best_top1       | float  | 85.20479026773415 |
| clipping_method | str    | MAX_BIT_SHIFT     |
| current_mAP     | int    | 0                 |
| current_top1    | float  | 85.20479026773415 |
+-----------------+--------+-------------------+
```


## myNet

python train.py --deterministic --model myunetsmall --out-fold-ratio 4 --dataset CamVid_s352_c3 --device MAX78000 --qat-policy policies/qat_policy_camvid.yaml --use-bias --evaluate -8 --exp-load-weights-from ../testB_unet/best-fakept-q.pth.tar --save-sample 10 --compiler-mode none

```

+----------------------+-------------+-------------+
| Key                  | Type        | Value       |
|----------------------+-------------+-------------|
| arch                 | str         | myunetsmall |
| compression_sched    | dict        |             |
| epoch                | int         | 25          |
| extras               | dict        |             |
| optimizer_state_dict | dict        |             |
| optimizer_type       | type        | Adam        |
| state_dict           | OrderedDict |             |
+----------------------+-------------+-------------+

=> Checkpoint['extras'] contents:
+-----------------+--------+-------------------+
| Key             | Type   | Value             |
|-----------------+--------+-------------------|
| best_epoch      | int    | 25                |
| best_mAP        | int    | 0                 |
| best_top1       | float  | 84.02443558453857 |
| clipping_method | str    | MAX_BIT_SHIFT     |
| current_mAP     | int    | 0                 |
| current_top1    | float  | 84.02443558453857 |
+-----------------+--------+-------------------+

```