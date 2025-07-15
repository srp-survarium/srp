void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getTopMostEntity(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        long double x,
        long double y,
        bool testAll)
{
  Scaleform::GFx::MovieImpl *v5; // esi
  Scaleform::GFx::DisplayObjectBase *pMainMovie; // ecx
  Scaleform::GFx::InteractiveObject *TopMostEntity; // eax
  int v8; // eax
  _DWORD *v9; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v10; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // ecx
  unsigned int RefCount; // eax
  float v13; // [esp+88h] [ebp-30h]
  float v14; // [esp+8Ch] [ebp-2Ch]
  Scaleform::Render::Point<float> v15; // [esp+90h] [ebp-28h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+98h] [ebp-20h] BYREF

  v5 = (Scaleform::GFx::MovieImpl *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  pMainMovie = v5->pMainMovie;
  if ( !pMainMovie )
    goto LABEL_11;
  pmat.M[0][0] = 1.0;
  pmat.M[0][1] = 0.0;
  pmat.M[0][2] = 0.0;
  pmat.M[0][3] = 0.0;
  pmat.M[1][0] = 0.0;
  pmat.M[1][2] = 0.0;
  pmat.M[1][3] = 0.0;
  pmat.M[1][1] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pMainMovie, &pmat);
  v13 = x * 20.0;
  v14 = 20.0 * y;
  v15.x = pmat.M[0][0] * v13 + v14 * pmat.M[0][1] + pmat.M[0][3];
  v15.y = v14 * pmat.M[1][1] + v13 * pmat.M[1][0] + pmat.M[1][3];
  TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(v5, &v15, 0.0, testAll, 0);
  if ( TopMostEntity )
  {
    v8 = (*(int (__thiscall **)(int))(*((_DWORD *)&TopMostEntity->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + TopMostEntity->AvmObjOffset)
                                    + 4))((int)TopMostEntity + 4 * TopMostEntity->AvmObjOffset);
    if ( v8 )
      v9 = (_DWORD *)(v8 - 28);
    else
      v9 = 0;
    (*(void (__thiscall **)(_DWORD *, int))(*v9 + 60))(v9, 1);
    v10 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v9[2];
    if ( !v10 )
      v10 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v9[1];
    if ( ((unsigned __int8)v10 & 1) != 0 )
      v10 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v10 - 1);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      v10);
  }
  else
  {
LABEL_11:
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
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
        result->pObject = 0;
      }
    }
  }
}
