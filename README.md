#### 使用C++实现设计模式  
#### 创建型  
##### 简单工厂模式（计算器）
- 创建型：接受指令，创建出符合要求的实例
- 简单工厂：用于产生同一等级架构的产品（无法增加新的产品）
##### 工厂模式（雷锋）
- 定义一个用于创建对象的接口，让子类决定去实例化那个类
- 工厂方法把简单工厂的内部判断逻辑移到了客户端代码，本来需要修改工厂类，现在是修改客户端。
- 简单工厂模式在增加功能是会违反开放-封闭原则。工厂方法模式借助多态，克服了该缺点，却保持了封装对象创建过程的优点。
##### 原型模式（简历）
- 用原型实例指定创建对象的种类，并通过拷贝这些原型创建新的对象
- 原型模式其实是从一个对象在创建另一个可定制的对象，而且不需要知道创建的细节
- 一般在初始化的信息不发生变化的情况下，克隆是最好的办法。既隐藏了创建的细节，又对性能有很大的提高。
- 原型模式不用重新初始化对象，而是获取对象运行时的状态。
- 原型抽象类的关键是有一个Clone()方法，原型具体类中复写Clone()创建当前对象的浅表副本。
- 在具体原型类中，MemberwiseClone()方法是浅拷贝，对值类型字段逐位拷贝，对引用类型只复制引用但不会把具体的对象值拷贝过来。原对象与他的副本引用同一个对象。
- 比起浅拷贝，深拷贝把引用对象的变量指向新对象，而不是原被引用的对象。对于需要深拷贝的每一层，都需要实现ICloneable原型模式。
- 深拷贝是把引用对象的变量指向复制过的新对象，而不是原有的被引用的对象。
#### 行为模式
##### 策略模式（商场销售）
- 面向对象中并非类越多越好，划分类是为了封装，但是分类的基础是抽象，相似的属性和功能的对象的抽象集合才是类
- 策略模式定义算法家族，分别封装，让他们之间可以替换。继承有助于析构公共的功能。这个模式让算法的变化不会影响到客户
- 策略模式和工厂模式结合，可以让客户端认识更少的类，降低耦合
- 策略模式可以简化单元测试，因为每个算法可以通过自己的借口单独测试
- 在不同时间内应用不同的业务规则，就可以考虑使用策略模式来处理
###### 模板方法（试卷）
- 模板方法模式：定义一个操作中的算法框架，将一些步骤延迟到子类中。子类在不改变框架的前提下就可以重新定义某些特定步骤。
- 当不变的和可变的行为在子类中混合在一起时，不变的部分就会重复出现，我们可以将不变的部分抽象成父类
#### 结构型
##### 装饰模式（装饰）
- 动态的给一个对象添加一些额外的功能，就增加功能而言，比生成子类更加方便。
- 每个要装饰的功能放在单独的类中，并让这个类包装它所要修饰的对象。当需要执行特殊行为时，客户端就可以根据需要有选择的、有顺序的使用装饰功能包装对象了。
- 装饰模式有效的把类的核心职能和装饰功能区分开了，并且可以去除相关类中重复的装饰逻辑。
##### 代理模式(礼物)
- 为其他对象提供一种代理以控制对这个对象的访问。实际上是在访问对象时引入一定程度的间接性，通过代理访问对象。
- 应用场合：远程代理,为一个对象在不同的地址空间提供局部代表，隐藏一个对象存在于不同空间的事实;如.Net加入Web引用，引入WebService，此时项目会生成WebReference的文件夹，就是代理
- 虚拟代理：根据需要创建开销很大的对象，通过它存放实例化需很长时间的真实对象。HTML中的多图，就是通过虚拟代理代替了真实图片，存储路径和尺寸。
- 安全代理：控制真实对象的访问权限，用于对象应该拥有不同的访问权限时。
- 智能指引：当调用真实对象时，代理处理一些另外的事情。通过代理在访问对象时增加一些内务处理。