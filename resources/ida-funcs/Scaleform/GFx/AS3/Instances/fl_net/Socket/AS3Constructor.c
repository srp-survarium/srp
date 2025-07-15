void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  const Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::ASStringNode *VStr; // edi
  int VInt; // ebp
  Scaleform::GFx::AS3::Value::V2U v10; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS3::Value hostIp; // [esp+18h] [ebp-10h] BYREF

  v3 = argc;
  v4 = argv;
  pVM = this->pTraits.pObject->pVM;
  hostIp.Flags = 0;
  hostIp.Bonus.pWeakProxy = 0;
  if ( argc && (argv->Flags & 0x1F) != 0 && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Value::Assign(&hostIp, argv);
    Scaleform::GFx::AS3::Value::ToStringValue(&hostIp, (Scaleform::GFx::AS3::CheckResult *)&argc, pVM->StringManagerRef);
    VStr = hostIp.value.VS._1.VStr;
  }
  else
  {
    VStr = 0;
    hostIp.Flags = 12;
    hostIp.value.VS._1.VInt = 0;
    hostIp.value.VS._2 = v10;
  }
  VInt = 0;
  if ( v3 > 1 && (v4[1].Flags & 0x1F) != 0 && ((v4[1].Flags & 0x1F) - 12 > 3 || v4[1].value.VS._1.VInt) )
    VInt = v4[1].value.VS._1.VInt;
  if ( (hostIp.Flags & 0x1F) != 0 && ((hostIp.Flags & 0x1F) - 12 > 3 || VStr) )
  {
    ++VStr->RefCount;
    Scaleform::GFx::AS3::Value::GetUndefined();
    Scaleform::GFx::AS3::SocketThreadMgr::Init(this->SockMgr.pObject, VStr->pData, VInt);
    if ( VStr->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  }
  if ( (hostIp.Flags & 0x1F) > 9 )
  {
    if ( (hostIp.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&hostIp);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&hostIp);
  }
}
