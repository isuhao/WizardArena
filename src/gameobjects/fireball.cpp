#include "fireball.hpp"
#include <glm/gtx/vector_angle.hpp>

#define TODEGREES (180.0 / 3.141592653589793238463)
#define LIFETIME 5.0

Fireball::Fireball(int owner, vec2 position, vec2 velocity) {
  this->owner    = owner;
  this->position = position;
  this->velocity = velocity;

  img = GPU_LoadImage("Content/Textures/Fireball.png");
  GPU_SetImageFilter(img, GPU_FILTER_NEAREST);

  birthTime = globals->Time;
  expired   = false;
}
Fireball::~Fireball() { GPU_FreeImage(img); }

void Fireball::Update() {
  if (globals->Time - birthTime > LIFETIME) { expired = true; }

  // Move
  if (velocity != vec2(0, 0)) {
    position += velocity * (float)GameObject::globals->DeltaTime;
  }
}
void Fireball::Draw() {
  float angle = 0;

  // Compute angle and save it
  if (velocity.x > 0) {
    angle = -glm::angle(vec2(0, 1), glm::normalize(velocity)) * TODEGREES + 180;
  } else {
    angle = glm::angle(vec2(0, 1), glm::normalize(velocity)) * TODEGREES + 180;
  }

  GPU_BlitTransform(img, nullptr, globals->backbuffer, position.x, position.y,
                    angle, 2.0f, 2.0f);
}

bool Fireball::Intersect(vec2 playerPosition) {
  if (glm::distance(position, playerPosition) < 143) {
    expired = true;
    return true;
  }
  return false;
}
