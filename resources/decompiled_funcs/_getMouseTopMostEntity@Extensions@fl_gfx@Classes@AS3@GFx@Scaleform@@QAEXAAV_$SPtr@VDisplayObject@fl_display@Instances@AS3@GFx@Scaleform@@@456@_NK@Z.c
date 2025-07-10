void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getMouseTopMostEntity(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        bool testAll,
        unsigned int mouseIndex)
{
  void (__thiscall *v4)(Scaleform::GFx::AS3::VM *); // esi
  unsigned int v5; // eax
  Scaleform::GFx::InteractiveObject *TopMostEntity; // eax
  int v7; // eax
  _DWORD *v8; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v9; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // ecx
  unsigned int RefCount; // eax
  float v12; // [esp+8h] [ebp-Ch]
  Scaleform::Render::Point<float> mousePos; // [esp+Ch] [ebp-8h] BYREF

  v4 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  if ( mouseIndex < (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v4 + 172))(v4) )
  {
    if ( mouseIndex < 6 )
      v5 = (unsigned int)v4 + 56 * mouseIndex + 4588;
    else
      v5 = 0;
    v12 = *(float *)(v5 + 36);
    mousePos.x = *(float *)(v5 + 32);
    mousePos.y = v12;
    TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(
                      (Scaleform::GFx::MovieImpl *)v4,
                      &mousePos,
                      mouseIndex,
                      testAll,
                      0);
    if ( TopMostEntity )
    {
      v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&TopMostEntity->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                        + TopMostEntity->AvmObjOffset)
                                      + 4))((int)TopMostEntity + 4 * TopMostEntity->AvmObjOffset);
      if ( v7 )
        v8 = (_DWORD *)(v7 - 28);
      else
        v8 = 0;
      (*(void (__thiscall **)(_DWORD *, int))(*v8 + 60))(v8, 1);
      v9 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v8[2];
      if ( !v9 )
        v9 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v8[1];
      if ( ((unsigned __int8)v9 & 1) != 0 )
        v9 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v9 - 1);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
        v9);
    }
    else
    {
      pObject = result->pObject;
      if ( result->pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
          result->pObject = 0;
        }
        else
        {
          RefCount = pObject->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
          }
          result->pObject = 0;
        }
      }
    }
  }
}
