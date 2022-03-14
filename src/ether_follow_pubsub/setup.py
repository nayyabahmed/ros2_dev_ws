from setuptools import setup

package_name = 'ether_follow_pubsub'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='nayab',
    maintainer_email='nayyabahmed@hotmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'efollow_sub = ether_follow_pubsub.ether_follow_sub:main',
            'efollow_pub = ether_follow_pubsub.ether_follow_pub:main',
            'external_follow = ether_follow_pubsub.external_follow:main'
        ],
    },
)
