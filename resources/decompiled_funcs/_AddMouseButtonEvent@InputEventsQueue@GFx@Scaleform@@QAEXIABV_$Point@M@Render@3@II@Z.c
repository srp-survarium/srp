void __thiscall Scaleform::GFx::InputEventsQueue::AddMouseButtonEvent(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned __int8 mouseIndex,
        const Scaleform::Render::Point<float> *pos,
        unsigned __int16 buttonsSt,
        unsigned __int8 flags)
{
  Scaleform::GFx::InputEventsQueue *v5; // eax

  if ( 1.1754944e-38 != pos->x )
    this->LastMousePosMask &= ~(1 << mouseIndex);
  v5 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v5->Queue[0].t = QE_Mouse;
  v5->Queue[0].u.mouseEntry.MouseIndex = mouseIndex;
  v5->Queue[0].u.mouseEntry.PosX = pos->x;
  v5->Queue[0].u.mouseEntry.PosY = pos->y;
  v5->Queue[0].u.mouseEntry.ButtonsState = buttonsSt;
  v5->Queue[0].u.mouseEntry.Flags = flags;
}
