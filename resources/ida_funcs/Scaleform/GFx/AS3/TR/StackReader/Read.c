int __thiscall Scaleform::GFx::AS3::TR::StackReader::Read(
        Scaleform::GFx::AS3::TR::StackReader *this,
        Scaleform::GFx::AS3::Multiname *obj)
{
  unsigned __int32 v2; // eax
  int v4; // eax
  Scaleform::GFx::AS3::Value result; // [esp+8h] [ebp-10h] BYREF

  v2 = obj->Kind - 1;
  while ( 2 )
  {
    switch ( v2 )
    {
      case 0u:
      case 8u:
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
          &this->StateRef->OpStack,
          &result);
        Scaleform::GFx::AS3::Value::~Value(&result);
        v4 = 1;
        break;
      case 4u:
      case 0xCu:
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
          &this->StateRef->OpStack,
          &result);
        Scaleform::GFx::AS3::Value::~Value(&result);
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
          &this->StateRef->OpStack,
          &result);
        Scaleform::GFx::AS3::Value::Assign(&obj->Name, &result);
        Scaleform::GFx::AS3::Value::~Value(&result);
        v4 = 2;
        break;
      case 5u:
      case 0xDu:
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
          &this->StateRef->OpStack,
          &result);
        Scaleform::GFx::AS3::Value::Assign(&obj->Name, &result);
        Scaleform::GFx::AS3::Value::~Value(&result);
        v4 = 1;
        break;
      case 0xFu:
        this->VMRef->UI->Output(this->VMRef->UI, Output_Warning, "Reading chained multiname in itself.");
        v2 = obj->Kind - 1;
        if ( v2 <= 0xF )
          continue;
        goto LABEL_4;
      default:
LABEL_4:
        v4 = 0;
        break;
    }
    return v4;
  }
}
