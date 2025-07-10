void __thiscall Scaleform::GFx::AS3::Value::ReleaseInternal(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::ASStringNode *VStr; // eax
  int VInt; // ecx

  switch ( this->Flags & 0x1F )
  {
    case 0xAu:
      VStr = this->value.VS._1.VStr;
      if ( VStr->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
      break;
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      VInt = this->value.VS._1.VInt;
      if ( (VInt & 1) == 0 )
        goto LABEL_6;
      this->value.VS._1.VInt = VInt - 1;
      break;
    case 0x10u:
    case 0x11u:
      VInt = (int)this->value.VS._2.VObj;
      if ( (VInt & 1) != 0 )
      {
        this->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)(VInt - 1);
      }
      else
      {
LABEL_6:
        if ( VInt )
          Scaleform::GFx::AS3::RefCountBaseGC<328>::Release((Scaleform::GFx::AS3::RefCountBaseGC<328> *)VInt);
      }
      break;
    default:
      return;
  }
}
