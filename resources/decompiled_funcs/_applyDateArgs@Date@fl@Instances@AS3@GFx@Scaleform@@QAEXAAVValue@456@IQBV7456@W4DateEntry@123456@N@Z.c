void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::applyDateArgs(
        Scaleform::GFx::AS3::Instances::fl::Date *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::AS3::Instances::fl::Date::DateEntry firstArg,
        long double tza)
{
  unsigned int v6; // ebx
  Scaleform::GFx::AS3::Instances::fl::Date::DateEntry v8; // esi
  Scaleform::GFx::AS3::Value *v9; // edi
  unsigned int Flags; // eax
  long double v11; // kr00_8
  Scaleform::GFx::AS3::Instances::fl::Date::DateHolder d; // [esp+20h] [ebp-28h] BYREF

  v6 = argc;
  if ( !argc )
    goto LABEL_10;
  Scaleform::GFx::AS3::Instances::fl::Date::DateHolder::DateHolder(&d, this->TimeValue, tza);
  v8 = firstArg;
  if ( v6 > 3 - firstArg )
    v6 = 3 - firstArg;
  v9 = argv;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &d.Entries[firstArg])->Result
    && (v6 < 2
     || Scaleform::GFx::AS3::Value::Convert2Number(
          v9 + 1,
          (Scaleform::GFx::AS3::CheckResult *)&argc,
          &d.Entries[v8 + 1])->Result)
    && (v6 < 3
     || Scaleform::GFx::AS3::Value::Convert2Number(
          v9 + 2,
          (Scaleform::GFx::AS3::CheckResult *)&argc,
          &d.Entries[v8 + 2])->Result) )
  {
    this->TimeValue = Scaleform::GFx::AS3::Instances::fl::Date::DateHolder::MakeDate(&d);
LABEL_10:
    Flags = result->Flags;
    tza = this->TimeValue;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
    v11 = tza;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = v11;
  }
}
