#ifndef BUTTON_H
#define BUTTON_H
#include "../gameobject.hpp"
#include "../includes.hpp"
#include "../shader.hpp"
#include "text.hpp"

class Button : public GameObject {
 public:
  Button(string text);
  virtual ~Button();
  // Draw GameObject
  void Draw() override;
  // Update GameObject
  void Update() override;
  // Input function
  void Input(SDL_Event event) override;

  // Set button state
  void SetState(byte state);

  // Hook a specific function
  void Hook(void (*f)(void));

  // Call the hooked function
  void Click() {
    if (hooked) func();
  };

 private:
  /* 0: default
     1: highlighted
     2: down
     3: text
   */
  static GPU_Image* buttonImages[3];
  Text*             buttonText;
  static bool       loaded;

  // Current state
  byte state;

  // Hooked function
  void (*func)(void);
  bool hooked = false;

  // Disabled shader
  Shader* disabledShader;
};

#endif /* BUTTON_H */
