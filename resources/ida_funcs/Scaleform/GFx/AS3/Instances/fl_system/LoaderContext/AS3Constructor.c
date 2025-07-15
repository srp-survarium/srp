void __thiscall Scaleform::GFx::AS3::Instances::fl_system::LoaderContext::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // edx
  const Scaleform::GFx::AS3::Value *v4; // eax
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *InstanceS; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *p_applicationDomain; // edi
  int v9; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // ecx

  v3 = argc;
  v4 = argv;
  if ( argc && (argv->Flags & 0x1F) != 0 && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt) )
    this->checkPolicyFile = argv->value.VS._1.VBool;
  if ( v3 > 1 && (v4[1].Flags & 0x1F) != 0 && ((v4[1].Flags & 0x1F) - 12 > 3 || v4[1].value.VS._1.VInt) )
  {
    v6 = v4[1].value.VS._1;
    InstanceS = (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstanceS(*(Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain **)(v6.VInt + 20), (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *)&argc, *(Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain **)(v6.VInt + 20));
    p_applicationDomain = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->applicationDomain;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(p_applicationDomain, InstanceS);
    if ( argc && (argc & 1) == 0 )
    {
      v9 = *(_DWORD *)(argc + 16);
      v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)argc;
      if ( ((unsigned int)&byte_3FFFFF & v9) != 0 )
      {
        *(_DWORD *)(argc + 16) = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
      }
    }
    p_applicationDomain->pObject->mAlign.Flags = *(_DWORD *)(v6.VInt + 32);
  }
}
