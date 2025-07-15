void __thiscall btDiscreteDynamicsWorld::removeCharacter(btDiscreteDynamicsWorld *this, btActionInterface *character)
{
  this->removeAction(this, character);
}
