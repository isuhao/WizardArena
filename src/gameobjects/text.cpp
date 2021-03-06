#include "text.hpp"

Text::Text(string text) {
  lastText = text;

  SDL_Color    col = {255, 255, 255, 255};
  SDL_Surface* textsurf =
      TTF_RenderText_Solid(globals->font, text.c_str(), col);
  textimg = GPU_CopyImageFromSurface(textsurf);
  SDL_FreeSurface(textsurf);
  GPU_SetImageFilter(textimg, GPU_FILTER_NEAREST);
  if (text.size()) {
    size.x = textimg->w;
    size.y = textimg->h;
  } else {
    size = vec2(0);
  }
}

Text::Text(string text, bool useSmallFont) {
  lastText = text;

  SDL_Color    col = {255, 255, 255, 255};
  SDL_Surface* textsurf;
  if (useSmallFont)
    textsurf = TTF_RenderText_Solid(globals->smallFont, text.c_str(), col);
  else
    textsurf = TTF_RenderText_Solid(globals->font, text.c_str(), col);
  textimg = GPU_CopyImageFromSurface(textsurf);
  SDL_FreeSurface(textsurf);
  if (text.size()) {
    size.x = textimg->w;
    size.y = textimg->h;
  } else {
    size = vec2(0);
  }
}

Text::Text(string text, SDL_Color color) {
  lastText = text;

  SDL_Surface* textsurf =
      TTF_RenderText_Solid(globals->font, text.c_str(), color);
  textimg = GPU_CopyImageFromSurface(textsurf);
  SDL_FreeSurface(textsurf);
  GPU_SetImageFilter(textimg, GPU_FILTER_NEAREST);
  if (text.size()) {
    size.x = textimg->w;
    size.y = textimg->h;
  } else {
    size = vec2(0);
  }
}

Text::Text(string text, SDL_Color color, bool useSmallFont) {
  lastText = text;

  SDL_Surface* textsurf;
  if (useSmallFont)
    textsurf = TTF_RenderText_Solid(globals->smallFont, text.c_str(), color);
  else
    textsurf = TTF_RenderText_Solid(globals->font, text.c_str(), color);
  textimg = GPU_CopyImageFromSurface(textsurf);
  SDL_FreeSurface(textsurf);
  if (text.size()) {
    size.x = textimg->w;
    size.y = textimg->h;
  } else {
    size = vec2(0);
  }
}

Text::~Text() { GPU_FreeImage(textimg); }
void Text::Draw() {
  GPU_Blit(textimg, nullptr, globals->backbuffer, position.x, position.y);
}

void Text::SetText(string text) {
  lastText = text;

  GPU_FreeImage(textimg);
  SDL_Color    col = {255, 255, 255, 255};
  SDL_Surface* textsurf =
      TTF_RenderText_Solid(globals->font, text.c_str(), col);
  textimg = GPU_CopyImageFromSurface(textsurf);
  SDL_FreeSurface(textsurf);
  GPU_SetImageFilter(textimg, GPU_FILTER_NEAREST);
  if (text.size()) {
    size.x = textimg->w;
    size.y = textimg->h;
  } else {
    size = vec2(0);
  }
}

void Text::SetText(string text, bool useSmallFont) {
  lastText = text;

  GPU_FreeImage(textimg);
  SDL_Color    col = {255, 255, 255, 255};
  SDL_Surface* textsurf;
  if (useSmallFont)
    textsurf = TTF_RenderText_Solid(globals->smallFont, text.c_str(), col);
  else
    textsurf = TTF_RenderText_Solid(globals->font, text.c_str(), col);
  textimg = GPU_CopyImageFromSurface(textsurf);
  SDL_FreeSurface(textsurf);
  GPU_SetImageFilter(textimg, GPU_FILTER_NEAREST);
  if (text.size()) {
    size.x = textimg->w;
    size.y = textimg->h;
  } else {
    size = vec2(0);
  }
}

void Text::SetText(string text, SDL_Color color) {
  lastText = text;

  GPU_FreeImage(textimg);
  SDL_Surface* textsurf =
      TTF_RenderText_Solid(globals->font, text.c_str(), color);
  textimg = GPU_CopyImageFromSurface(textsurf);
  SDL_FreeSurface(textsurf);
  GPU_SetImageFilter(textimg, GPU_FILTER_NEAREST);
  if (text.size()) {
    size.x = textimg->w;
    size.y = textimg->h;
  } else {
    size = vec2(0);
  }
}

void Text::SetText(string text, SDL_Color color, bool useSmallFont) {
  lastText = text;

  GPU_FreeImage(textimg);
  SDL_Surface* textsurf;
  if (useSmallFont)
    textsurf = TTF_RenderText_Solid(globals->smallFont, text.c_str(), color);
  else
    textsurf = TTF_RenderText_Solid(globals->font, text.c_str(), color);
  textimg = GPU_CopyImageFromSurface(textsurf);
  SDL_FreeSurface(textsurf);
  GPU_SetImageFilter(textimg, GPU_FILTER_NEAREST);
  if (text.size()) {
    size.x = textimg->w;
    size.y = textimg->h;
  } else {
    size = vec2(0);
  }
}
