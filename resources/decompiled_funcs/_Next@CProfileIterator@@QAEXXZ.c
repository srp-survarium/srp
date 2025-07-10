void __usercall CProfileIterator::Next(CProfileIterator *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(*(_DWORD *)(a2 + 4) + 28);
}
