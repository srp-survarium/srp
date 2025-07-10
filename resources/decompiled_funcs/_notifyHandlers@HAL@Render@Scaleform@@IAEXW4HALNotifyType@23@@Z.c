void __thiscall Scaleform::Render::HAL::notifyHandlers(
        Scaleform::Render::HAL *this,
        Scaleform::Render::HALNotifyType type)
{
  Scaleform::Render::HALNotify *pNext; // eax
  Scaleform::List<Scaleform::Render::HALNotify,Scaleform::Render::HALNotify> *p_NotifyList; // edi
  int v4; // ecx
  Scaleform::Render::HALNotify *v5; // esi

  pNext = this->NotifyList.Root.pNext;
  p_NotifyList = &this->NotifyList;
  while ( 1 )
  {
    v4 = p_NotifyList ? (int)&p_NotifyList[-1].Root.4 : 0;
    if ( pNext == (Scaleform::Render::HALNotify *)v4 )
      break;
    v5 = pNext->pNext;
    pNext->OnHALEvent(pNext, type);
    pNext = v5;
  }
}
