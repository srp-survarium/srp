void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::styleSheetSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *value)
{
  Scaleform::GFx::TextField *pObject; // edi
  int v4; // eax
  int v5; // esi
  Scaleform::GFx::AS3::AvmTextField::CSSHolder *v6; // eax
  Scaleform::GFx::TextField::CSSHolderBase *v7; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *CSSData; // eax
  Scaleform::Render::Text::EditorKitBase *v9; // eax
  unsigned int v10; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // ecx
  _DWORD *v12; // esi
  unsigned int RefCount; // eax

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  v4 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                    + pObject->AvmObjOffset)
                                  + 4))((int)pObject + 4 * pObject->AvmObjOffset);
  if ( v4 )
    v5 = v4 - 28;
  else
    v5 = 0;
  if ( value )
  {
    if ( !Scaleform::GFx::TextField::GetCSSData((Scaleform::GFx::AS3::SocketThreadMgr *)pObject) )
    {
      v6 = (Scaleform::GFx::AS3::AvmTextField::CSSHolder *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             68,
                                                             0);
      if ( v6 )
        Scaleform::GFx::AS3::AvmTextField::CSSHolder::CSSHolder(v6);
      else
        v7 = 0;
      Scaleform::GFx::TextField::SetCSSData(pObject, v7);
    }
    CSSData = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)Scaleform::GFx::TextField::GetCSSData(*(Scaleform::GFx::AS3::SocketThreadMgr **)(v5 + 12));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      CSSData + 16,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)value);
    v9 = pObject->pDocument.pObject->pEditorKit.pObject;
    if ( v9 )
      LOWORD(v9[16].__vftable) |= 1u;
    Scaleform::GFx::TextField::SetDirtyFlag(*(Scaleform::GFx::TextField **)(v5 + 12));
  }
  else if ( Scaleform::GFx::TextField::GetCSSData(*(Scaleform::GFx::AS3::SocketThreadMgr **)(v5 + 12)) )
  {
    v10 = Scaleform::GFx::TextField::GetCSSData(*(Scaleform::GFx::AS3::SocketThreadMgr **)(v5 + 12));
    v11 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v10 + 64);
    v12 = (_DWORD *)(v10 + 64);
    if ( v11 )
    {
      if ( ((unsigned __int8)v11 & 1) != 0 )
      {
        *v12 = (char *)v11 - 1;
      }
      else
      {
        RefCount = v11->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
      }
      *v12 = 0;
    }
  }
  Scaleform::GFx::TextField::CollectUrlZones(pObject);
  Scaleform::GFx::TextField::UpdateUrlStyles(pObject);
  pObject->Flags |= (unsigned int)&_sbh_sizeHeaderList;
}
