Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Traits::AddSlots(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Abc::HasTraits *traits,
        Scaleform::GFx::AS3::VMAbcFile *file,
        unsigned int parent_size)
{
  const Scaleform::GFx::AS3::Abc::HasTraits *v5; // ebx
  Scaleform::GFx::AS3::VMAbcFile *v6; // edi
  Scaleform::GFx::AS3::CheckResult *v8; // eax
  Scaleform::GFx::AS3::CheckResult v9; // [esp+Fh] [ebp-5h] BYREF
  int v10; // [esp+10h] [ebp-4h]

  v5 = traits;
  v6 = file;
  v10 = 0;
  if ( Scaleform::GFx::AS3::Traits::AddSlotsWithID(this, (Scaleform::GFx::AS3::CheckResult *)&file, traits, file)->Result
    && Scaleform::GFx::AS3::Traits::AddSlotsWithoutID(this, (Scaleform::GFx::AS3::CheckResult *)&traits, v5, v6, 1)->Result
    && Scaleform::GFx::AS3::Traits::AddSlotsWithoutID(this, &v9, v5, v6, 0)->Result )
  {
    Scaleform::GFx::AS3::Traits::CalculateMemSize(this, parent_size);
    v8 = result;
    result->Result = 1;
  }
  else
  {
    v8 = result;
    result->Result = 0;
  }
  return v8;
}
