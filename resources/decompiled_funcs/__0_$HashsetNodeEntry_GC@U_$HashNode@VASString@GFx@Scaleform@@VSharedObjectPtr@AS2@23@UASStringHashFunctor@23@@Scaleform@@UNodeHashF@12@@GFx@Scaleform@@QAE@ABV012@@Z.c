void __thiscall Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>(
        Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *this,
        const Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *e)
{
  Scaleform::GFx::ASStringNode *pNode; // edx
  Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject> *v3; // edx

  this->NextInChain = e->NextInChain;
  pNode = e->Value.First.pNode;
  this->Value.First.pNode = pNode;
  ++pNode->RefCount;
  if ( e == (const Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)-8 )
    v3 = 0;
  else
    v3 = &e->Value.Second.Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject>;
  if ( v3->pObject )
    v3->pObject->RefCount = (v3->pObject->RefCount + 1) & 0x8FFFFFFF;
  this->Value.Second.Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject> = (Scaleform::Ptr<Scaleform::GFx::AS2::SharedObject>)v3->pObject;
  this->Value.Second.__vftable = (Scaleform::GFx::AS2::SharedObjectPtr_vtbl *)&Scaleform::GFx::AS2::SharedObjectPtr::`vftable';
}
