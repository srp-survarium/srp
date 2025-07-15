Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASString::Substring(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result,
        char *start,
        char *end)
{
  Scaleform::GFx::ASStringNode *v4; // eax

  v4 = Scaleform::GFx::ASConstString::SubstringNode(this, start, end);
  ++v4->RefCount;
  result->pNode = v4;
  return result;
}
