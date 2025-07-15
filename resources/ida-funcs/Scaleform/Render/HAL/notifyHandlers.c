void __thiscall Scaleform::Render::HAL::notifyHandlers(
        Scaleform::Render::HAL *this,
        Scaleform::Render::HALNotifyType type)
{
  Scaleform::Render::HALNotify *pNext; // esi
  Scaleform::List<Scaleform::Render::HALNotify,Scaleform::Render::HALNotify> *p_NotifyList; // ebx
  const Scaleform::Render::HALNotify *v4; // edi

  pNext = this->NotifyList.Root.pNext;
  p_NotifyList = &this->NotifyList;
  if ( !Scaleform::List<Scaleform::Render::HALNotify,Scaleform::Render::HALNotify>::IsNull(&this->NotifyList, pNext) )
  {
    do
    {
      v4 = pNext->pNext;
      pNext->OnHALEvent(pNext, type);
      pNext = (Scaleform::Render::HALNotify *)v4;
    }
    while ( !Scaleform::List<Scaleform::Render::HALNotify,Scaleform::Render::HALNotify>::IsNull(p_NotifyList, v4) );
  }
}
