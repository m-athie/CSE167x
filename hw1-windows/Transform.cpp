// Transform.cpp: implementation of the Transform class.

#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
  // Convert degrees to radian
  const float radians = degrees * pi / 180.0;

  // find sinTheta
  const float sinTheta = sin(radians);
  // find cosTheta
  const float cosTheta = cos(radians);
  // normalize vector 3
  const vec3 a = normalize(axis);
  
  //Compute rotation of first basis vector
  mat3 m;

  glm::vec3 normalizedAxis = glm::normalize(axis);
  glm::mat3 rotationMatrix(1.0f);

  rotationMatrix[0][0] = cosTheta + (1 - cosTheta) * normalizedAxis.x * normalizedAxis.x;
  rotationMatrix[0][1] = (1 - cosTheta) * normalizedAxis.x * normalizedAxis.y - sinTheta * normalizedAxis.z;
  rotationMatrix[0][2] = (1 - cosTheta) * normalizedAxis.x * normalizedAxis.z + sinTheta * normalizedAxis.y;
  rotationMatrix[1][0] = (1 - cosTheta) * normalizedAxis.y * normalizedAxis.x + sinTheta * normalizedAxis.z;
  rotationMatrix[1][1] = cosTheta + (1 - cosTheta) * normalizedAxis.y * normalizedAxis.y;
  rotationMatrix[1][2] = (1 - cosTheta) * normalizedAxis.y * normalizedAxis.z - sinTheta * normalizedAxis.x;
  rotationMatrix[2][0] = (1 - cosTheta) * normalizedAxis.z * normalizedAxis.x - sinTheta * normalizedAxis.y;
  rotationMatrix[2][1] = (1 - cosTheta) * normalizedAxis.z * normalizedAxis.y + sinTheta * normalizedAxis.x;
  rotationMatrix[2][2] = cosTheta + (1 - cosTheta) * normalizedAxis.z * normalizedAxis.z;

  // return Transform?
  //mat4 inv = inverse(m);
  // You will change this return call
  return rotationMatrix;
}


// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	const float radians = degrees * pi / 180.0;
	vec3 x(0, 1, 0);
	mat3 resultEyeMatrix = Transform::rotate(radians, x);
	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
	eye = eye * resultEyeMatrix;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE 
	const float radians = degrees * pi / 180.0;
	vec3 x(1, 0, 0);
	mat3 resultEyeMatrix = Transform::rotate(radians, x);
	eye = eye * resultEyeMatrix;
	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
  return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}