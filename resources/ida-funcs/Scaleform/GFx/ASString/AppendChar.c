Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASString::AppendChar(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result,
        unsigned int ch)
{
  Scaleform::GFx::ASStringNode *appended; // eax

  appended = Scaleform::GFx::ASConstString::AppendCharNode(this, ch);
  ++appended->RefCount;
  result->pNode = appended;
  return result;
}
