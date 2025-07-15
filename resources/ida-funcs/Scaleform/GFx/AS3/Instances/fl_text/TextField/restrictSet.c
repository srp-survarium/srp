void __userpurge Scaleform::GFx::AS3::Instances::fl_text::TextField::restrictSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this@<ecx>,
        int a2@<ebx>,
        const Scaleform::GFx::AS3::Value *result,
        const __m128i ***value)
{
  Scaleform::GFx::TextField *pObject; // ecx

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  if ( *value == (const __m128i **)&(*value)[1][3].m128i_u64[1] )
    Scaleform::GFx::TextField::ClearRestrict(pObject);
  else
    Scaleform::GFx::TextField::SetRestrict(pObject, a2, value);
}
