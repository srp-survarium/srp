void __userpurge PPM_CONTEXT::update1(ppmd_compressor_impl *impl@<edx>, PPM_CONTEXT::STATE *p@<eax>, PPM_CONTEXT *this)
{
  PPM_CONTEXT::STATE *v3; // ecx
  __int16 v4; // si
  PPM_CONTEXT *Successor; // edi

  impl->FoundState = p;
  p->Freq += 4;
  this->SummFreq += 4;
  if ( p->Freq > p[-1].Freq )
  {
    v3 = p - 1;
    v4 = *(_WORD *)&p->Symbol;
    *(_WORD *)&p->Symbol = *(_WORD *)&p[-1].Symbol;
    Successor = p->Successor;
    p->Successor = p[-1].Successor;
    v3->Successor = Successor;
    *(_WORD *)&v3->Symbol = v4;
    impl->FoundState = p - 1;
    if ( p[-1].Freq > 0x7Cu )
      PPM_CONTEXT::rescale((PPM_CONTEXT *)v3, (ppmd_compressor_impl *)this);
  }
}
