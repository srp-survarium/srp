void __thiscall Scaleform::GFx::AS3::InstanceTraits::Traits::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::AS3::Value *result,
        int t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // esi
  Scaleform::GFx::AS3::VM *v4; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v6; // eax
  Scaleform::GFx::AS3::Object *v7; // eax

  v3 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)t;
  v4 = *(Scaleform::GFx::AS3::VM **)(t + 64);
  v5 = *(_DWORD *)(t + 52);
  t = 337;
  v6 = (Scaleform::GFx::AS3::Instances::fl::Object *)v4->MHeap->Alloc(v4->MHeap, v5, (const Scaleform::AllocInfo *)&t);
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v6, v3);
    Scaleform::GFx::AS3::Value::Pick(result, v7);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Pick(result, 0);
  }
}
