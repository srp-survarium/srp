void __thiscall Scaleform::GFx::InputEventsQueue::AddMouseMove(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int mouseIndex,
        const Scaleform::Render::Point<float> *pos)
{
  if ( mouseIndex < 6 )
  {
    this->LastMousePosMask |= 1 << mouseIndex;
    this->LastMousePos[mouseIndex].x = pos->x;
    this->LastMousePos[mouseIndex].y = pos->y;
  }
}
