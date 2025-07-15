void __thiscall btDiscreteDynamicsWorld::addCharacter(btDiscreteDynamicsWorld *this, btActionInterface *character)
{
  this->addAction(this, character);
}
