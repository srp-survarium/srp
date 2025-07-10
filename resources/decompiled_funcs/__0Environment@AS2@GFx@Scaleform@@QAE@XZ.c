void __thiscall Scaleform::GFx::AS2::Environment::Environment(Scaleform::GFx::AS2::Environment *this)
{
  this->__vftable = (Scaleform::GFx::AS2::Environment_vtbl *)&Scaleform::GFx::AS2::Environment::`vftable';
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PagedStack<Scaleform::GFx::AS2::Value,32>(&this->Stack);
  this->GlobalRegister[0].T.Type = 0;
  this->GlobalRegister[1].T.Type = 0;
  this->GlobalRegister[2].T.Type = 0;
  this->GlobalRegister[3].T.Type = 0;
  this->LocalRegister.Data.Data = 0;
  this->LocalRegister.Data.Size = 0;
  this->LocalRegister.Data.Policy.Capacity = 0;
  this->Target = 0;
  this->StringContext.pContext = 0;
  this->StringContext.SWFVersion = 0;
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>(&this->CallStack);
  this->pASLogger = 0;
  this->TryBlocks.Data.Data = 0;
  this->TryBlocks.Data.Size = 0;
  this->TryBlocks.Data.Policy.Capacity = 0;
  this->ThrowingValue.T.Type = 10;
  *((_BYTE *)this + 194) &= 0xFCu;
  this->ExecutionNestingLevel = 0;
  this->FuncCallNestingLevel = 0;
  this->LocalFrames.Data.Data = 0;
  this->LocalFrames.Data.Size = 0;
  this->LocalFrames.Data.Policy.Capacity = 0;
}
