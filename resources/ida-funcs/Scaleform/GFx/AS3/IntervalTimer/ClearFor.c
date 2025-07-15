char __thiscall Scaleform::GFx::AS3::IntervalTimer::ClearFor(
        Scaleform::GFx::AS3::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot,
        Scaleform::GFx::MovieDefImpl *defimpl)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_Function; // ecx
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  int v7; // eax
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *pObject; // eax
  int v10; // eax

  Flags = this->Function.Flags;
  p_Function = &this->Function;
  if ( (Flags & 0x1F) - 12 <= 3 && !p_Function->value.VS._1.VInt
    || (ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(
                        (Scaleform::GFx::AS3::VM *)proot->pASMovieRoot.pObject[2].__vftable,
                        p_Function),
        (v7 = (int)ValueTraits->GetFilePtr(ValueTraits)) == 0)
    || *(Scaleform::GFx::MovieDefImpl **)(*(_DWORD *)(v7 + 60) + 192) != defimpl )
  {
    pObject = this->TimerObj.pObject;
    if ( !pObject )
      return 0;
    v10 = (int)pObject->pTraits.pObject->GetFilePtr(pObject->pTraits.pObject);
    if ( !v10 || *(Scaleform::GFx::MovieDefImpl **)(*(_DWORD *)(v10 + 60) + 192) != defimpl )
      return 0;
  }
  this->Clear(this);
  return 1;
}
