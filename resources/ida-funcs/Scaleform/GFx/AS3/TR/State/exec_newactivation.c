void __thiscall Scaleform::GFx::AS3::TR::State::exec_newactivation(Scaleform::GFx::AS3::TR::State *this)
{
  const Scaleform::GFx::AS3::CallFrame *CF; // eax
  Scaleform::GFx::AS3::Abc::MbiInd v3; // edx
  Scaleform::GFx::AS3::VMFile *pFile; // ecx
  Scaleform::GFx::AS3::Value val; // [esp+4h] [ebp-10h] BYREF

  CF = this->pTracer->CF;
  v3.Ind = CF->MBIIndex.Ind;
  pFile = CF->pFile;
  val.Bonus.pWeakProxy = 0;
  val.value.VS._1.VInt = (int)Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(pFile, v3);
  val.Flags = 8;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->OpStack.Data,
    &val);
}
