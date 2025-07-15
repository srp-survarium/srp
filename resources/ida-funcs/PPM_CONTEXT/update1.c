void __userpurge PPM_CONTEXT::update1(PPM_CONTEXT::STATE *p@<eax>, PPM_CONTEXT *this, ppmd_compressor_impl *impl)
{
  __int16 v3; // dx
  PPM_CONTEXT::STATE *v4; // ecx
  PPM_CONTEXT *Successor; // edi

  impl->FoundState = p;
  p->Freq += 4;
  this->SummFreq += 4;
  if ( p->Freq > p[-1].Freq )
  {
    v3 = *(_WORD *)&p->Symbol;
    v4 = p - 1;
    *(_WORD *)&p->Symbol = *(_WORD *)&p[-1].Symbol;
    Successor = p->Successor;
    p->Successor = p[-1].Successor;
    *(_WORD *)&v4->Symbol = v3;
    v4->Successor = Successor;
    impl->FoundState = p - 1;
    if ( p[-1].Freq > 0x7Cu )
      PPM_CONTEXT::rescale((PPM_CONTEXT *)v4, &this->NumStats, impl);
  }
}
