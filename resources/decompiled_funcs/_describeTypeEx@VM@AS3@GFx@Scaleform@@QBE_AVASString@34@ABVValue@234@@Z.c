Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::VM::describeTypeEx(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASString *v4; // eax

  pNode = this->StringManagerRef->Builtins[0].pNode;
  v4 = result;
  ++pNode->RefCount;
  result->pNode = pNode;
  return v4;
}
