Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::CharacterDef *pdef,
        const Scaleform::Render::Point<float> *pt,
        bool testAll,
        const Scaleform::GFx::InteractiveObject *ignoreMC)
{
  Scaleform::GFx::InteractiveObject *pParent; // esi
  unsigned __int8 AvmObjOffset; // al
  int v9; // eax
  int v10; // eax
  unsigned __int8 v11; // cl
  int v12; // eax
  Scaleform::Render::Point<float> p; // [esp+4h] [ebp-8h] BYREF

  if ( !this->GetVisible(this) )
    return 0;
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &p, pt, 1, 0);
  if ( !this->ClipDepth && pdef->DefPointTestLocal(pdef, &p, 1, this) )
  {
    pParent = this->pParent;
    if ( pParent )
    {
      while ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
      {
        if ( testAll
          || (AvmObjOffset = pParent->AvmObjOffset) != 0
          && (v9 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                + AvmObjOffset)
                                              + 4))((int)pParent + 4 * AvmObjOffset),
              (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 52))(v9))
          || ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetMatrix)(pParent)
          && (v10 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetMatrix)(pParent),
              (v11 = *(_BYTE *)(v10 + 65)) != 0)
          && (v12 = (*(int (__thiscall **)(int))(*(_DWORD *)(v10 + 4 * v11) + 4))(v10 + 4 * v11),
              (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v12 + 52))(v12)) )
        {
          if ( !ignoreMC || ignoreMC != pParent )
            return pParent;
        }
        pParent = pParent->pParent;
        if ( !pParent )
          return 0;
      }
    }
  }
  return 0;
}
