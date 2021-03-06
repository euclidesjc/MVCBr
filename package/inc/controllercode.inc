FormViewCreate = 'Application.CreateForm(T%FormIdentView, view)';
NormalViewCreate = 'view := T%FormIdentView.create(nil)';
NormalViewDestory = 'freeAndNil(view)';

ControllerCode =
  'unit %ModelIdent;                                                ' + #10#13 +
  '                                                                 ' + #10#13 +
  'interface                                                        ' + #10#13 +
  '//%include                                                       ' + #10#13 +
  'uses                                                             ' + #10#13 +
  '                                                                 ' + #10#13 +
  'SysUtils, forms, buttons, classes, controls,MVCBr.Interf,        ' + #10#13 +
  'MVCBr.Model, MVCBr.Controller, MVCBr.ApplicationController,      ' + #10#13 +
  'System.RTTI,                                                     ' + #10#13 +
  '%FormIdent.ViewModel, %FormIdent.ViewModel.Interf,%FormIdentView;' + #10#13 +
  '                                                                 ' + #10#13 +
  'type                                                             ' + #10#13 +
  '                                                                 ' + #10#13 +
  '  I%FormIdentController = interface(IController)' + #10#13 +
  '         [''%guid'']                                             ' + #10#13 +
  '         // incluir especializações aqui                         ' + #10#13 +
  '  end;                                                           ' + #10#13 +
  '                                                                 ' + #10#13 +
  '  T%FormIdentController = class(TControllerFactory,              ' + #10#13 +
  '    I%FormIdentController,                                       ' + #10#13 +
  '    IThisAs<T%FormIdentController>, IModelAs<I%FormIdentViewModel>)  ' +
  #10#13 + '  protected                                            ' + #10#13 +
  '    Procedure DoCommand(ACommand: string;                      ' + #10#13 +
  '        const AArgs: array of TValue); override;                 ' + #10#13 +
  '  public                                                         ' + #10#13 +
  '    // inicializar os módulos personalizados em CreateModules    ' + #10#13 +
  '    Procedure CreateModules;virtual;                             ' + #10#13 +
  '    Constructor Create;override;                                 ' + #10#13 +
  '    Destructor Destroy; override;                                ' + #10#13 +
  '    class function New(): IController; overload;                 ' + #10#13 +
  '    class function New(const AView: IView; const AModel: IModel) ' + #10#13 +
  '      : IController; overload;                                   ' + #10#13 +
  '    class function New(const AModel: IModel): IController; overload;' +
  #10#13 + '    function ThisAs: T%FormIdentController;             ' + #10#13 +
  '    procedure init;override;                                     ' + #10#13 +
  '    function ModelAs: I%FormIdentViewModel;                          ' +
  #10#13 + '  end;                                                  ' + #10#13 +
  '                                                                 ' + #10#13 +
  'implementation                                                   ' + #10#13 +
  '                                                                 ' + #10#13 +
  'Constructor T%FormIdentController.Create;                        ' + #10#13 +
  'begin                                                            ' + #10#13 +
  ' inherited;                                                     ' + #10#13 +
  ' add(T%FormIdentViewModel.New(self).ID(''{%FormIdent.ViewModel}''));' +
  ' CreateModules; //< criar os modulos persolnizados              ' + #10#13 +
  #10#13 + 'end;                                                ' + #10#13 +
  '                                                                 ' + #10#13 +
  'Destructor T%FormIdentController.destroy;                        ' + #10#13 +
  'begin                                                            ' + #10#13 +
  '  inherited;                                                     ' + #10#13 +
  'end;                                                             ' + #10#13 +
  '                                                                 ' + #10#13 +
  'class function T%FormIdentController.New(): IController;         ' + #10#13 +
  'begin                                                            ' + #10#13 +
  ' result := new(nil,nil);                                         ' + #10#13 +
  'end;                                                             ' + #10#13 +
  '                                                                 ' + #10#13 +
  'class function T%FormIdentController.New(const AView: IView; ' + #10#13 +
  '   const AModel: IModel) : IController;                          ' + #10#13 +
  'var                                                              ' + #10#13 +
  '  vm: IViewModel;                                                ' + #10#13 +
  'begin                                                            ' + #10#13 +
  '  result := T%FormIdentController.create as IController;         ' + #10#13 +
  '  result.View(AView).Add(AModel);                                ' + #10#13 +
  '  if assigned(AModel) then                                       ' + #10#13 +
  '    if supports(AModel.This, IViewModel, vm) then                ' + #10#13 +
  '      begin                                                      ' + #10#13 +
  '        vm.View(AView).Controller( result );                     ' + #10#13 +
  '      end;                                                       ' + #10#13 +
  'end;                                                             ' + #10#13 +
  '                                                                 ' + #10#13 +
  'class function T%FormIdentController.New(                        ' + #10#13 +
  '   const AModel: IModel): IController;                           ' + #10#13 +
  'begin                                                            ' + #10#13 +
  '  result := new(nil,AModel);                                     ' + #10#13 +
  'end;                                                             ' + #10#13 +
  '                                                                 ' + #10#13 +
  'function T%FormIdentController.ThisAs: T%FormIdentController;    ' + #10#13 +
  'begin                                                            ' + #10#13 +
  '   result := self;                                               ' + #10#13 +
  'end;                                                             ' + #10#13 +
  '                                                                 ' + #10#13 +
  'function T%FormIdentController.ModelAs: I%FormIdentViewModel;' + #10#13 +
  'begin                                                            ' + #10#13 +
  ' if count>=0 then                                                ' + #10#13 +
  '  supports(GetModelByType(mtViewModel), I%FormIdentViewModel, result);' +
  #10#13 + 'end;                                           ' + #10#13 +
  '                                                                 ' + #10#13 +
  'Procedure T%FormIdentController.DoCommand(ACommand: string;      ' + #10#13 +
  '   const AArgs:Array of TValue);                                 ' + #10#13 +
  'begin                                                            ' + #10#13 +
  '    inherited;                                                   ' + #10#13 +
  'end;                                                      ' + #10#13 +
  '                                                                 ' + #10#13 +
  'procedure T%FormIdentController.init;                            ' + #10#13 +
  'var ref:T%FormIdentView;                                               ' + #10#13 +
  'begin                                                            ' + #10#13 +
  '  inherited;                                                     ' + #10#13 +
  ' if not assigned(FView) then                            ' + #10#13 +
  ' begin                                                           ' + #10#13 +
  '   Application.CreateForm( T%FormIdentView, ref );                 ' + #10#13
  + '   supports(ref,IView,FView);                            ' + #10#13 +
  ' end;                                                            ' + #10#13 +
  ' AfterInit;                                                        ' + #10#13 +
  'end;                                                             ' + #10#13 +

  ' // Adicionar os modulos e MODELs personalizados              ' + #10#13 +
  'Procedure T%FormIdentController.CreateModules;                   ' + #10#13 +
  'begin                                                            ' + #10#13 +
  '   // adicionar os mudulos aqui                                  ' + #10#13 +
  '   // exemplo: add( MeuModel.new(self) );                        ' + #10#13 +
  'end;                                                             ' + #10#13 +

  '                                                                 ' + #10#13 +
  'initialization                                                   ' + #10#13 +
  '//T%FormIdentController.New(T%FormIdentView.New,T%FormIdentViewModel.New)).init();'
  + #10#13 + '                                                     ' + #10#13 +
  '  RegisterInterfacedClass(T%FormIdentController.ClassName,I%FormIdentController,T%FormIdentController);'
  + #10#13 + '                                                     ' + #10#13 +
  'finalization                                                    ' + #10#13 +
  '                                                                 ' + #10#13 +
  '  unRegisterInterfacedClass(T%FormIdentController.ClassName);' + #10#13 +
  '                                                                 ' + #10#13 +
  'end.                                                          ' + #10#13;

ControllerCode2 = ControllerCode;

ControllerCodeWithoutModel = ControllerCode;

ControllerCodeWithoutView = ControllerCode;

ControllerCodeOnly = ControllerCode;
