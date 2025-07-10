void __thiscall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::inputModeSet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::VM *pVM; // ebx
  Scaleform::GFx::MovieImpl::MultitouchInputMode v4; // edi

  pVM = this->pTraits.pObject->pVM;
  v4 = MTI_None;
  if ( !strcmp(value->pNode->pData, "touchPoint") )
  {
    v4 = MTI_TouchPoint;
  }
  else if ( !strcmp(value->pNode->pData, "gesture") )
  {
    v4 = MTI_Gesture;
  }
  else if ( !strcmp(value->pNode->pData, "mixed") )
  {
    v4 = MTI_Mixed;
  }
  Scaleform::GFx::MovieImpl::SetMultitouchInputMode(
    (Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM,
    v4);
}
