Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat> *__thiscall Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat>::`vector deleting destructor'(
        Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat> *this,
        char a2)
{
  this->__vftable = (Scaleform::StatInfo_InterfaceImpl<Scaleform::MemoryStat>_vtbl *)&Scaleform::StatInfo::StatInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
