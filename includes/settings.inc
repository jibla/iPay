<?php

/**
 * settings form's callback for Drupal's form API
 *
 * @return Array
 * @author Giorgi Jibladze
 */
function ipay_settings_form() {
	$form = array();
	
	$form['ipay_service_enabled'] = array(
	 '#type'          =>	'checkbox',
	 '#title'         =>	t('Service is enabled'),
	 '#default_value' =>	variable_get('ipay_service_enabled', 1),
	);

	
	$form['ipay_service_url'] = array(
	 '#type'          => 'textfield',
	 '#disabled'			=> TRUE,
	 '#title'         => t('Service URL'),
	 '#default_value' => variable_get('ipay_service_url', ''),
	 '#description'   => t("send this URL to iPay's technical team"),
	 '#value'	=> url('ipay-server', array('absolute' => TRUE)),
	 '#required'      => TRUE,
	);
	
	$form['ipay_username'] = array(
	 '#type'          => 'textfield',
	 '#title'         => t('Username'),
	 '#default_value' => variable_get('ipay_username', ''),
	 '#description'   => t("for iPay service"),
	 '#required'      => TRUE,
	);

	$form['ipay_password'] = array(
	 '#type'          => 'textfield',
	 '#title'         => t('Password'),
	 '#default_value' => variable_get('ipay_password', ''),
	 '#description'   => t("for iPay service"),
	 '#required'      => TRUE,
	);
	
	$form['ipay_secret_key'] = array(
	 '#type'          => 'textfield',
	 '#title'         => t('Secret Key'),
	 '#default_value' => variable_get('ipay_secret_key', ''),
	 '#description'   => t("for hashing parameters"),
	 '#required'      => TRUE,
	);
	
	$form['ipay_host'] = array(
	 '#type'          => 'textfield',
	 '#title'         => t('iPay\'s servers IP Address(es)'),
	 '#default_value' => variable_get('ipay_host', ''),
	 '#description'   => t("specify range with dash. e.g. 176.221.231.45-176.221.231.145"),
	 '#required'      => FALSE,
	);
	

	return system_settings_form($form);
}
