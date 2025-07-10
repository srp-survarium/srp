void __thiscall Scaleform::GFx::AS3::Instances::fl_media::ID3Info::~ID3Info(
        Scaleform::GFx::AS3::Instances::fl_media::ID3Info *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v3; // zf
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::GFx::ASStringNode *v5; // ecx
  Scaleform::GFx::ASStringNode *v6; // ecx
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::ASStringNode *v8; // ecx
  Scaleform::GFx::ASStringNode *v9; // ecx

  pNode = this->year.pNode;
  v3 = pNode->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v4 = this->track.pNode;
  v3 = v4->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v5 = this->songName.pNode;
  v3 = v5->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v6 = this->genre.pNode;
  v3 = v6->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v7 = this->comment.pNode;
  v3 = v7->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v8 = this->artist.pNode;
  v3 = v8->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v9 = this->album.pNode;
  v3 = v9->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
