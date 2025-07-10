void __thiscall Scaleform::GFx::InputEventsQueue::AddMouseWheel(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned __int8 mouseIndex,
        const Scaleform::Render::Point<float> *pos,
        char delta)
{
  Scaleform::GFx::InputEventsQueue *v4; // eax

  if ( 1.1754944e-38 != pos->x )
    this->LastMousePosMask &= ~(1 << mouseIndex);
  v4 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v4->Queue[0].t = QE_Mouse;
  v4->Queue[0].u.mouseEntry.MouseIndex = mouseIndex;
  v4->Queue[0].u.mouseEntry.PosX = pos->x;
  v4->Queue[0].u.mouseEntry.PosY = pos->y;
  v4->Queue[0].u.mouseEntry.WheelScrollDelta = delta;
  v4->Queue[0].u.mouseEntry.ButtonsState = 0;
  v4->Queue[0].u.mouseEntry.Flags = 32;
}
