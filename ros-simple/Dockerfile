FROM ros:humble

SHELL ["/bin/bash", "-c"]

COPY ./src /root/

WORKDIR /root

RUN source /opt/ros/humble/setup.bash && colcon build --packages-select docker3 

RUN echo '#!/bin/bash' > /ros_entrypoint.sh
RUN echo 'set -e' >> /ros_entrypoint.sh
RUN echo 'source /opt/ros/humble/setup.bash' >> /ros_entrypoint.sh
RUN echo 'source /root/install/setup.bash' >> /ros_entrypoint.sh
RUN echo 'exec "$@"' >> /ros_entrypoint.sh 
RUN chmod +x /ros_entrypoint.sh

ENTRYPOINT ["/ros_entrypoint.sh"]
