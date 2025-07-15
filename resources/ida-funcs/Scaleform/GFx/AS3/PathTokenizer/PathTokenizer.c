void __thiscall Scaleform::GFx::AS3::PathTokenizer::PathTokenizer(
        Scaleform::GFx::AS3::PathTokenizer *this,
        const char *ppath)
{
  this->Path.pStr = ppath;
  if ( ppath )
    this->Path.Size = strlen(ppath);
  else
    this->Path.Size = 0;
  this->Token.pStr = 0;
  this->Token.Size = 0;
}
