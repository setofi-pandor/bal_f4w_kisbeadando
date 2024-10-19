# `bal_f4w_kisbeadando` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/setofi-pandor/bal_f4w_kisbeadando
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select bal_f4w_kisbeadando --symlink-install
```

<details>

``` r
ros2 launch sze_sw1_szinusz launch_example1.launch.py
```

``` r
ros2 run sze_sw1_szinusz gen_node 
```

``` r
ros2 run sze_sw1_szinusz sum_node 
```
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch bal_f4w_kisbeadando launch_example1.launch.py
```


## Graph

<p align="center"><img src="img/mermaid_diagramm.png" width="60%" /></p>

<p align="center"><img src="img/függvény_vizualizálás.png" width="60%" /></p>

<p align="center"><img src="img/mermaid_diagramm_node-topic(active).png" width="60%" /></p>
