void __thiscall Scaleform::GFx::AS3::VM::GetStackTraceASString(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *result,
        const char *line_pref)
{
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v4; // ecx

  pNode = this->StringManagerRef->Builtins[2].pNode;
  ++pNode->RefCount;
  v4 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  result->pNode = pNode;
}
