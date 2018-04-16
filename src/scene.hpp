#ifndef SCENE_HPP
#define SCENE_HPP

#include "gameobject.hpp"

/*
  Handels a collection of game objects.
*/
class Scene {
 public:
  // Constructor
  Scene();
  // Destructor
  virtual ~Scene();
  // Draws scene
  void Draw();
  // Updates scene
  void Update();
  // Trigger input for the appropriate scenes
  void Input(SDL_Event* event);

 protected:
  // Variables
  vector<GameObject*> gameObjects;
  vector<string>      messages;
  bool                dead;
  // GPU_Target* target;
};

#endif /* SCENE_HPP */
