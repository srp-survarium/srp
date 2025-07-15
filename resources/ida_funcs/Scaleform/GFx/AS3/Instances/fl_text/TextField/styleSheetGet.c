void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::styleSheetGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> *result)
{
  int v2; // eax
  int v3; // esi
  const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *CSSData; // eax

  v2 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->pDispObj.pObject->Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::__vftable
                                       + this->pDispObj.pObject->AvmObjOffset)
                                     + 4))(
         (char *)&this->pDispObj.pObject->Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::__vftable
       + 4 * this->pDispObj.pObject->AvmObjOffset);
  if ( v2 )
    v3 = v2 - 28;
  else
    v3 = 0;
  if ( Scaleform::GFx::TextField::GetCSSData(*(Scaleform::GFx::AS3::SocketThreadMgr **)(v3 + 12)) )
  {
    if ( *(_DWORD *)(Scaleform::GFx::TextField::GetCSSData(*(Scaleform::GFx::AS3::SocketThreadMgr **)(v3 + 12)) + 64) )
    {
      CSSData = (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)Scaleform::GFx::TextField::GetCSSData(*(Scaleform::GFx::AS3::SocketThreadMgr **)(v3 + 12));
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)result,
        CSSData + 16);
    }
  }
}
