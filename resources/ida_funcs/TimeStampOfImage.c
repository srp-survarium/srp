unsigned int __usercall TimeStampOfImage@<eax>(_IMAGE_NT_HEADERS *pinh@<eax>)
{
  return pinh->FileHeader.TimeDateStamp;
}
