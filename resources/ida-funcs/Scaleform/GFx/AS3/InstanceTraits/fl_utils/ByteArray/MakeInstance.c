Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *t)
{
  Scaleform::GFx::AS3::Instances::fl::Catch *v2; // eax
  Scaleform::GFx::AS3::Instances::fl::Catch *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v2, t);
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)&Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::`vftable';
    v3[1].__vftable = (Scaleform::GFx::AS3::Instances::fl::Catch_vtbl *)((int)v3[1].__vftable & 0xFFFFFFE0
                                                                       | (int)Scaleform::GFx::AS3::Traits::GetConstructor(t)[1].__vftable
                                                                       & 7);
    v4 = result;
    v3[1].pRCCRaw = 0;
    v3[1].pNext = 0;
    v3[1].pPrev = 0;
    v3[1].RefCount = 0;
    v3[1].pTraits.pObject = 0;
    result->pV = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)v3;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
