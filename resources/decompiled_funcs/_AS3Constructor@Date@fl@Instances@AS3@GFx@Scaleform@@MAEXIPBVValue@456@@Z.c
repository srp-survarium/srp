void __userpurge Scaleform::GFx::AS3::Instances::fl::Date::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::Date *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  int *p_LocalTZA; // edi
  long double *p_TimeValue; // ebp
  int *VInt; // ebx
  double Date; // st7
  Scaleform::GFx::AS3::Value arg; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Date::Parser parsedDate; // [esp+28h] [ebp-28h] BYREF

  p_LocalTZA = &this->LocalTZA;
  p_TimeValue = &this->TimeValue;
  Scaleform::GFx::AS3::Instances::fl::Date::GetCurrentTimeValue(a2, &this->TimeValue, &this->LocalTZA);
  if ( argc )
  {
    if ( argc != 1 )
    {
      *p_TimeValue = Scaleform::GFx::AS3::Instances::fl::Date::decodeUTCArgs(argc, argv, (double)*p_LocalTZA);
      return;
    }
    arg.Flags = 0;
    arg.Bonus.pWeakProxy = 0;
    if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
           argv,
           (Scaleform::GFx::AS3::CheckResult *)&argv,
           &arg,
           hintString)->Result )
    {
      if ( (arg.Flags & 0x1F) == 0xA )
      {
        VInt = (int *)arg.value.VS._1.VInt;
        ++*(_DWORD *)(arg.value.VS._1.VInt + 12);
        Scaleform::GFx::AS3::Instances::fl::Date::Parser::Parser(&parsedDate, *VInt);
        if ( VInt[3]-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)VInt);
        Date = Scaleform::GFx::AS3::Instances::fl::Date::Parser::MakeDate(&parsedDate, *p_LocalTZA);
      }
      else
      {
        if ( !Scaleform::GFx::AS3::Value::ToNumberValue(&arg, (Scaleform::GFx::AS3::CheckResult *)&argc)->Result )
        {
          Scaleform::GFx::AS3::Value::~Value(&arg);
          return;
        }
        Date = Scaleform::GFx::AS3::Instances::fl::Date::TimeClip(arg.value.VNumber);
      }
      *p_TimeValue = Date;
    }
    if ( (arg.Flags & 0x1F) > 9 )
    {
      if ( (arg.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&arg);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&arg);
    }
  }
  else
  {
    this->UseDST = 1;
  }
}
